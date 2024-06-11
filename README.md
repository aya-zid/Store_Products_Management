Store Management System
Welcome to the Store Management System! This project is designed to manage products in a store efficiently. It's written in C language and features a graphical interface for easy interaction.

- Features
Data Structure: Utilizes a singly linked list to store product information including code (ID), name, production date, expiration date, price, and quantity.

Menu Bar: The menu bar provides easy access to various functions:

Chargement: Uploads product data from a text file named "produit" upon the first run. It initializes the product list.

Enregistrement: Saves any changes made to the products back to the "produit" text file.

Update products : Allows you to:

Add a new product at the head, tail, or specific position.
Delete a product from the head, tail, specific position, or by product code. You can also delete all expired products.
Modify a product's price or quantity by providing the product code.
Recherche, affichage et Tri: Enables you to:

View the contents of the product list.
Search for a product by its code, production date, or expiration date.
Sort products in descending order of quantity or ascending order of expiration date.
Ouvrir un Fichier: Lets you open either the "produit" text file to view its contents or the project statement PDF file.

Error Handling: Ensures data integrity by validating inputs. You'll receive error pop-up messages if you enter incorrect data or forget to load the initial products.

- Usage
First Run: Click on "Creation" to initialize the product list and add the first product. This step is only required once.
Subsequent Runs: Simply click on "Chargement" to load existing products from the "produit" file. Then, use other menu functions as needed.
Saving Changes: Always remember to click on "Enregistrement" after making any modifications to save them back to the text file.
- Notes
Ensure correct data entry:
Quantity must be a positive number.
Product code should consist of three digits.
Dates must be valid.
Price should be a positive float.
Avoid clicking "Creation" after the first run unless you want to start a new product list from scratch.

If you have any questions or encounter any issues, feel free to reach out.
