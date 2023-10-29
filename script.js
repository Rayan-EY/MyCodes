let contacts = [];

function addContact() {
    const name = document.getElementById('name').value;
    const email = document.getElementById('email').value;
    const phone = document.getElementById('phone').value;

    if (!validatePhoneNumber()) {
        return; // Prevent adding the contact if phone number is invalid
    }

    contacts.push({ name, email, phone });

    updateContactList();
    document.getElementById('contactForm').reset();
}

function updateContactList(contactsToShow) {
    const contactList = document.getElementById('contactList');
    contactList.innerHTML = '';

    const contactsToDisplay = contactsToShow || contacts;

    contactsToDisplay.forEach(contact => {
        const listItem = document.createElement('div');
        listItem.className = 'contact-item';
        listItem.innerHTML = `
            <strong>Name:</strong> ${contact.name}<br>
            <strong>Email:</strong> ${contact.email}<br>
            <strong>Phone:</strong> ${contact.phone}
        `;
        contactList.appendChild(listItem);
    });
}




// Linear search function
function searchContacts() {
    const query = document.getElementById('searchInput').value.toLowerCase();
    const filteredContacts = linearSearch(contacts, query);
    updateContactList(filteredContacts);
}

function validatePhoneNumber() {
    var phoneNumber = document.getElementById("phone").value;
    // Use a regular expression to validate the phone number format
    var phoneNumberPattern = /^[0-9]{10}$/; // You can adjust this pattern as needed
    if (!phoneNumberPattern.test(phoneNumber)) {
        alert("Please enter a valid 10-digit phone number.");
        return false;
    }
    return true;
}



function linearSearch(arr, query) {
    const filteredContacts = [];
    for (const contact of arr) {
        if (contact.name.toLowerCase().includes(query)) {
            filteredContacts.push(contact);
        }
    }
    return filteredContacts;
}

// Bubble sort function
function sortContacts() {
    bubbleSort(contacts);
    updateContactList();
}

function bubbleSort(arr) {
    const n = arr.length;
    for (let i = 0; i < n - 1; i++) {
        let swapped = false;
        for (let j = 0; j < n - i - 1; j++) {
            if (arr[j].name.localeCompare(arr[j + 1].name) > 0) {
                // Swap the elements
                const temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // If no two elements were swapped, the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

// script.js
function goToHome() {
    window.location.href = "home.html"; // Replace "index.html" with the actual filename of your home page
}


