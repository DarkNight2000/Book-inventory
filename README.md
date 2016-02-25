# Book-inventory

This program is able to store and process data for a bookstore which deals in classic book titles. The user will enter data about the book titles to be stored in the inventory system, and will select options related to what to do with the data.The number of different book titles will be entered by the user, so the code must be able to deal with an indeterminate number of different books.


First, the program should prompt the user to enter data about the books. The data will be entered in the following format, with each item of data listed entered on a different line:


Book title (possibly containing white space characters)

Author's name (possibly containing white space characters)

Book stock number (1 – 10000; assume no duplicates)

Wholesale price in dollars (a floating point value)

Retail price in dollars (a floating point value)

Wholesale quantity purchased by bookstore (a whole number greater than zero)

Retail quantity purchased by customers (a whole number greater than zero)


Data about each book will not be separated from the data for the following book; that is, the first line of input for the next book will immediately follow the book which precedes it. The end of the input for the books will be marked by the string END_DATA, which will appear at the beginning of the line on the next line after the end of the data for the last book. There will be data about
at least one book in the input. 


The linked list for the books should store them in order of increasing book stock number, but the books will not necessarily appear in the input in this order. After reading the input data about the books, and constructing the linked list, the program should
repeatedly prompt the user to select from the following options for processing of the data :


1. Determine and print total revenue (from all books)

2. Determine and print total wholesale cost (for all books)

3. Determine and print total profit (for all books: this is total revenue minus total wholesale cost)

4. Determine and print total number of books sold for all books

5. Determine and print average profit per sale (total profit divided by total number of sales)

6. Print book list (print Book list: on one line, preceded by a blank line, then the names of all books,
each on a separate line, in order of increasing stock number, with the last book followed by a
single blank line)

7. Add book (prompt the user to enter the book data, in the format given above): this should add a
single book to the initial list, after it is built as described above

8. Delete book (prompt the user to enter the book stock number: if the book stock number is not
found in the linked list, print a message indicating an error; if the list is empty, print a distinct
message indicating this error)

9. Exit the program


The user will enter a choice of one of these nine options by entering a single digit, 1-9, immediately followed by enter (new line). After performing the chosen operation, your program should prompt the user to select another operation, and continue to perform this cycle (prompt for operation, perform operation) over and over again, until the user finally selects option 9 to exit the program.
Assume that all user input will be correct, except that the user may inadvertently attempt to delete a book which has not been added to the list of books. 
