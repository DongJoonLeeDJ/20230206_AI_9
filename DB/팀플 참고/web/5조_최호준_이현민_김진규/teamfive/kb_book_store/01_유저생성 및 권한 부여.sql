create database kb_book_store;

CREATE USER 'kb_bookstore_admin'@'%' IDENTIFIED BY 'kbadmin';

GRANT all privileges ON `kb_book_store`.* TO 'kb_bookstore_admin'@'%' WITH GRANT OPTION;

FLUSH PRIVILEGES;