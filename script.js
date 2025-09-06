// Sample book data
let books = [
    {
        id: 1,
        title: "The Great Gatsby",
        author: "F. Scott Fitzgerald",
        genre: "Fiction",
        price: 12.99,
        description: "A classic American novel set in the 1920s, exploring themes of wealth, love, and the American Dream.",
        seller: "Classic Books Store"
    },
    {
        id: 2,
        title: "To Kill a Mockingbird",
        author: "Harper Lee",
        genre: "Fiction",
        price: 14.99,
        description: "A powerful story of racial injustice and childhood innocence in the American South.",
        seller: "Literary Classics"
    },
    {
        id: 3,
        title: "1984",
        author: "George Orwell",
        genre: "Fiction",
        price: 13.99,
        description: "A dystopian novel about totalitarianism, surveillance, and the loss of individual freedom.",
        seller: "Orwell Books"
    },
    {
        id: 4,
        title: "The Catcher in the Rye",
        author: "J.D. Salinger",
        genre: "Fiction",
        price: 11.99,
        description: "A coming-of-age story following teenager Holden Caulfield in New York City.",
        seller: "Modern Literature"
    },
    {
        id: 5,
        title: "Dune",
        author: "Frank Herbert",
        genre: "Sci-Fi",
        price: 16.99,
        description: "An epic science fiction novel set on the desert planet Arrakis.",
        seller: "Sci-Fi Central"
    },
    {
        id: 6,
        title: "The Hobbit",
        author: "J.R.R. Tolkien",
        genre: "Fiction",
        price: 15.99,
        description: "A fantasy adventure following Bilbo Baggins on his unexpected journey.",
        seller: "Fantasy Books"
    },
    {
        id: 7,
        title: "Pride and Prejudice",
        author: "Jane Austen",
        genre: "Romance",
        price: 10.99,
        description: "A romantic novel about Elizabeth Bennet and Mr. Darcy in 19th-century England.",
        seller: "Classic Romance"
    },
    {
        id: 8,
        title: "The Da Vinci Code",
        author: "Dan Brown",
        genre: "Mystery",
        price: 13.49,
        description: "A mystery thriller involving religious symbolism and conspiracy theories.",
        seller: "Mystery House"
    }
];

// Seller's books (books added by the current user)
let sellerBooks = [];

// Shopping cart
let cart = [];

// Initialize the application
document.addEventListener('DOMContentLoaded', function() {
    displayBooks(books);
    displaySellerBooks();
    updateCartCount();
    updateCartDisplay();
    
    // Add form submission handler
    document.getElementById('add-book-form').addEventListener('submit', addBook);
});

// Show different sections
function showSection(sectionName) {
    // Hide all sections
    const sections = document.querySelectorAll('.section');
    sections.forEach(section => section.classList.remove('active'));
    
    // Show selected section
    const targetSection = document.getElementById(sectionName + '-section');
    if (targetSection) {
        targetSection.classList.add('active');
    }
    
    // Update cart display when cart section is shown
    if (sectionName === 'cart') {
        updateCartDisplay();
    }
}

// Display books in the grid
function displayBooks(booksToShow) {
    const booksGrid = document.getElementById('books-grid');
    
    if (booksToShow.length === 0) {
        booksGrid.innerHTML = `
            <div class="empty-state">
                <h3>No books found</h3>
                <p>Try adjusting your search criteria</p>
            </div>
        `;
        return;
    }
    
    booksGrid.innerHTML = booksToShow.map(book => `
        <div class="book-card" onclick="showBookDetails(${book.id})">
            <div class="book-title">${book.title}</div>
            <div class="book-author">by ${book.author}</div>
            <div class="book-genre">${book.genre}</div>
            <div class="book-price">$${book.price.toFixed(2)}</div>
            <div class="book-description">${book.description}</div>
            <button class="btn btn-success" onclick="event.stopPropagation(); addToCart(${book.id})">
                Add to Cart
            </button>
        </div>
    `).join('');
}

// Search books
function searchBooks() {
    const searchTerm = document.getElementById('search-input').value.toLowerCase();
    const selectedGenre = document.getElementById('genre-filter').value;
    
    const filteredBooks = books.filter(book => {
        const matchesSearch = book.title.toLowerCase().includes(searchTerm) ||
                            book.author.toLowerCase().includes(searchTerm) ||
                            book.genre.toLowerCase().includes(searchTerm);
        
        const matchesGenre = !selectedGenre || book.genre === selectedGenre;
        
        return matchesSearch && matchesGenre;
    });
    
    displayBooks(filteredBooks);
}

// Filter books by genre
function filterBooks() {
    searchBooks(); // Reuse search function as it handles both search and filter
}

// Show book details in modal
function showBookDetails(bookId) {
    const book = books.find(b => b.id === bookId);
    if (!book) return;
    
    const modalContent = document.getElementById('modal-book-details');
    modalContent.innerHTML = `
        <h2>${book.title}</h2>
        <p><strong>Author:</strong> ${book.author}</p>
        <p><strong>Genre:</strong> <span class="book-genre">${book.genre}</span></p>
        <p><strong>Price:</strong> <span class="book-price">$${book.price.toFixed(2)}</span></p>
        <p><strong>Seller:</strong> ${book.seller}</p>
        <p><strong>Description:</strong></p>
        <p>${book.description}</p>
        <button class="btn btn-success" onclick="addToCart(${book.id}); closeModal();">
            Add to Cart
        </button>
    `;
    
    document.getElementById('book-modal').style.display = 'block';
}

// Close modal
function closeModal() {
    document.getElementById('book-modal').style.display = 'none';
}

// Close modal when clicking outside
window.onclick = function(event) {
    const modal = document.getElementById('book-modal');
    if (event.target === modal) {
        modal.style.display = 'none';
    }
}

// Add book to cart
function addToCart(bookId) {
    const book = books.find(b => b.id === bookId);
    if (!book) return;
    
    // Check if book is already in cart
    const existingItem = cart.find(item => item.id === bookId);
    if (existingItem) {
        showMessage('Book is already in your cart!', 'error');
        return;
    }
    
    cart.push({...book});
    updateCartCount();
    showMessage('Book added to cart!', 'success');
}

// Remove book from cart
function removeFromCart(bookId) {
    cart = cart.filter(item => item.id !== bookId);
    updateCartCount();
    updateCartDisplay();
}

// Update cart count in navigation
function updateCartCount() {
    document.getElementById('cart-count').textContent = cart.length;
}

// Update cart display
function updateCartDisplay() {
    const cartItems = document.getElementById('cart-items');
    const cartTotal = document.getElementById('cart-total');
    
    if (cart.length === 0) {
        cartItems.innerHTML = `
            <div class="empty-state">
                <h3>Your cart is empty</h3>
                <p>Add some books to get started!</p>
            </div>
        `;
        cartTotal.textContent = '0.00';
        return;
    }
    
    cartItems.innerHTML = cart.map(item => `
        <div class="cart-item">
            <div class="cart-item-details">
                <div class="cart-item-title">${item.title}</div>
                <div class="cart-item-author">by ${item.author}</div>
            </div>
            <div class="cart-item-price">$${item.price.toFixed(2)}</div>
            <button class="btn btn-danger" onclick="removeFromCart(${item.id})">Remove</button>
        </div>
    `).join('');
    
    const total = cart.reduce((sum, item) => sum + item.price, 0);
    cartTotal.textContent = total.toFixed(2);
}

// Checkout function
function checkout() {
    if (cart.length === 0) {
        showMessage('Your cart is empty!', 'error');
        return;
    }
    
    const total = cart.reduce((sum, item) => sum + item.price, 0);
    showMessage(`Thank you for your purchase! Total: $${total.toFixed(2)}`, 'success');
    
    // Clear cart
    cart = [];
    updateCartCount();
    updateCartDisplay();
}

// Add new book (seller functionality)
function addBook(event) {
    event.preventDefault();
    
    const title = document.getElementById('book-title').value;
    const author = document.getElementById('book-author').value;
    const genre = document.getElementById('book-genre').value;
    const price = parseFloat(document.getElementById('book-price').value);
    const description = document.getElementById('book-description').value;
    
    const newBook = {
        id: Date.now(), // Simple ID generation
        title,
        author,
        genre,
        price,
        description,
        seller: 'You'
    };
    
    // Add to seller's books
    sellerBooks.push(newBook);
    
    // Add to main books array so it appears in buyer section
    books.push(newBook);
    
    // Clear form
    document.getElementById('add-book-form').reset();
    
    // Update displays
    displaySellerBooks();
    displayBooks(books);
    
    showMessage('Book added successfully!', 'success');
}

// Display seller's books
function displaySellerBooks() {
    const sellerBooksContainer = document.getElementById('seller-books-list');
    
    if (sellerBooks.length === 0) {
        sellerBooksContainer.innerHTML = `
            <div class="empty-state">
                <h3>No books listed yet</h3>
                <p>Add your first book using the form above!</p>
            </div>
        `;
        return;
    }
    
    sellerBooksContainer.innerHTML = sellerBooks.map(book => `
        <div class="seller-book-card">
            <div class="book-title">${book.title}</div>
            <div class="book-author">by ${book.author}</div>
            <div class="book-genre">${book.genre}</div>
            <div class="book-price">$${book.price.toFixed(2)}</div>
            <button class="btn btn-danger" onclick="removeSellerBook(${book.id})">
                Remove
            </button>
        </div>
    `).join('');
}

// Remove seller's book
function removeSellerBook(bookId) {
    // Remove from seller's books
    sellerBooks = sellerBooks.filter(book => book.id !== bookId);
    
    // Remove from main books array
    books = books.filter(book => book.id !== bookId);
    
    // Remove from cart if it's there
    cart = cart.filter(item => item.id !== bookId);
    
    // Update displays
    displaySellerBooks();
    displayBooks(books);
    updateCartCount();
    updateCartDisplay();
    
    showMessage('Book removed successfully!', 'success');
}

// Show success/error messages
function showMessage(message, type) {
    // Remove existing messages
    const existingMessages = document.querySelectorAll('.message');
    existingMessages.forEach(msg => msg.remove());
    
    // Create new message
    const messageDiv = document.createElement('div');
    messageDiv.className = `message ${type}`;
    messageDiv.textContent = message;
    
    // Insert at the top of the active section
    const activeSection = document.querySelector('.section.active .container');
    if (activeSection) {
        activeSection.insertBefore(messageDiv, activeSection.firstChild);
        
        // Auto-remove after 3 seconds
        setTimeout(() => {
            messageDiv.remove();
        }, 3000);
    }
}