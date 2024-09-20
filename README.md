
### Shopify Inventory Management System

Welcome to the **Shopify Inventory Management System**. This system enables users to manage products, keep track of items in stock, and perform both customer and admin operations.

### Features

1. **Display Products**:
   - Displays all available products in the inventory with details including ID, name, price, quantity, and category.
   - Products can also be sorted by **name**, **price**, or **category**.

2. **Add Products to Cart**:
   - Users can search for products by **ID** and add them to their cart.
   - Products are only added if sufficient quantity is available in the inventory.

3. **Check Product Availability**:
   - Users can verify if a specific product is available in the desired quantity.

4. **Admin Mode**:
   - Admins can add, update, or delete products in the inventory.
   - Password-protected admin mode.

5. **Generate Bill**:
   - Users can proceed to checkout, view the total bill, and save the bill to a file.

6. **File Management**:
   - The inventory and cart can be saved to and loaded from files.

### Admin Operations

Admins can:
   - **Add Products**: Admins can add products to the inventory by specifying the ID, name, price, quantity, and category.
   - **Update Products**: Modify existing product details (name, price).
   - **Delete Products**: Remove products from the inventory.
   - **View and Sort Products**: Admins can view and sort products by various criteria.

### Sorting & Searching

The system provides the ability to:
   - **Sort by Price**: Sort products in ascending order based on their price.
   - **Sort by Name**: Sort alphabetically by product name.
   - **Sort by Category**: Sort by predefined categories, including "Electronics," "Apparels," and "Food Items."

### Cart Management

- **Add to Cart**: Users can add items to the cart and adjust the quantity.
- **View Cart**: The cart's contents can be displayed, and the total cost is calculated.
- **Checkout**: Once satisfied, the user can check out, generating a bill saved to a file.

### Binary Search for Product Lookup

- The system uses **binary search** to quickly locate products by their ID, ensuring efficient search operations.

### Admin Mode Access

To access admin functionalities, use the password `root123`. Admin mode provides additional control over the inventory, including adding, updating, and deleting products.

### Example Commands

1. **Display Inventory**:
   ```
   1. Display Inventory
   ```

2. **Search Product by ID**:
   ```
   2. Enter Product ID: 10
   Output: Product ID: 10, Name: Apple Macbook Pro M2, Price: Rs 250000, Quantity: 40, Category: Electronics
   ```

3. **Admin - Add Product**:
   ```
   Admin Options -> Add Product
   Enter Product ID: 31
   Enter Product Name: Samsung Galaxy S23
   Enter Product Price: Rs 85000
   Enter Product Quantity: 20
   Enter Product Category: Electronics
   ```

### File Handling

- **Save Inventory to File**: Inventory is saved to a file (`Inventory.txt`), and can be loaded at the start of the program.
- **Save Cart to File**: Cart contents are saved to a file (`cart.txt`).
- **Save Bill to File**: A bill is generated and saved to a file (`bill.txt`).

### Conclusion

This system is a user-friendly platform for managing a product-based inventory system, offering both regular user and admin functionalities. Admins can efficiently maintain inventory, while users can explore products, add them to the cart, and check out with ease.

### Future Enhancements

- Integration of a GUI for better user interaction.
- Introduction of discounts or promotional offers.

---

