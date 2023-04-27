
/** SELECT BASICO */


/* Seleccionar todos las las filas de la tabla de clientes */
SELECT * FROM CUSTOMERS;

/* Seleccionar sólo las columnas first_namey last_name de la tabla de clientes */
SELECT first_name, last_name FROM CUSTOMERS;

/* Selección de todas las filas y columnas de la tabla de clientes de New York, ordenadas por apellidos y nombre */
SELECT * FROM CUSTOMERS WHERE city='New York' ORDER BY last_name, first_name;

/* Selección de todos (filas y columnas) los empleados */
SELECT * FROM STAFFS;

/* Selección de todas (filas y columnas) las marcas */
SELECT * FROM BRANDS;

/* Selección de todas (filas y columnas) las categorías */
SELECT * FROM CATEGORIES;

/* Selección de todas los productos (filas y columnas) cuyo precio esté entre 100 y 500, ordenado por precio descendentemente */
SELECT * FROM PRODUCTS WHERE list_price BETWEEN 100 AND 500 ORDER BY LIST_PRICE DESC;


/**** EJERCICIOS: ****/
/* 1. Seleccionar productos con precio superior a 1000 */
/* 2. Seleccionar nombres y correos electrónicos de tiendas de Santa Cruz */
/* 3. Seleccionar precio+descuento de todos los items vendidos */
/* 4. Seleccionar el email del personal cuyo nombre y apellidos es Fabiola Jackson */
/* 5. Seleccionar el personal que no tenga manager. Es obligatorio hacer uso de la condición IS NULL en la consulta */






/** PRODUCTO CARTESIANO */

/* Consulta todos los atributos de empleados cuyos jefes se llaman Mireya */
SELECT staffs.* FROM staffs, staffs jefes WHERE staffs.manager_id=jefes.staff_id AND jefes.first_name='Mireya';

/* Nombre, apellidos, código postal, fecha de pedido y estado del pedido de clientes que han realizado pedidos con fecha superior a 2017 (del 1 de Enero de 2018 en adelante)
   ordenados por fecha de pedido */
SELECT first_name, last_name, zip_code, order_date, order_status FROM CUSTOMERS, ORDERS WHERE CUSTOMERS.customer_id=ORDERS.customer_id AND order_date>= TO_DATE('2018/01/01', 'yyyy/mm/dd') ORDER BY order_date;

/* Nombre, apellidos y nombre de la tienda donde trabajan los empleados, ordenados por nombre de tienda ascendentemente, y por apellidos descendentemente en caso de empate */
SELECT first_name, last_name, store_name FROM staffs, stores WHERE staffs.store_id=stores.store_id ORDER BY store_name, last_name DESC;



/**** EJERCICIOS: ****/
/* 6. Seleccionar nombre y apellidos de personal (staffs) que hayan procesado pedidos de clientes de la ciudad de New York */
/* 7. Seleccionar nombres de tiendas que tienen productos de la categoría Mountain Bikes */
/* 8. Seleccionar nombres de productos vendidos, y cantidad, a clientes que viven en Bronx */
/* 9. Seleccionar nombre y apellidos de clientes que han comprado productos de la categoría Mountain Bikes */
/* 10. Seleccionar las marcas que ha vendido el personal de la tienda localizada en Santa Cruz */


/** OPERADORES ADICIONALES */


/* Seleccionar el precio promedio, su desviación típica, precio mínimo y precio máximo de productos */
SELECT AVG(list_price), STDDEV(list_price), MIN(list_price), MAX(list_price) FROM PRODUCTS;

/* Seleccionar el nombre del producto de mínimo precio, junto con su marca, categoría y precio */
SELECT product_name, brand_name, category_name, list_price FROM PRODUCTS, BRANDS, CATEGORIES WHERE PRODUCTS.brand_id=BRANDS.brand_id AND
                                                                PRODUCTS.category_id=CATEGORIES.category_id AND
                                                                list_price<=ALL(SELECT P2.list_price FROM PRODUCTS P2);

/* Seleccionar el nombre del producto de máximo precio, junto con su marca, categoría y precio */
SELECT product_name, brand_name, category_name, list_price FROM PRODUCTS, BRANDS, CATEGORIES WHERE PRODUCTS.brand_id=BRANDS.brand_id AND
                                                                PRODUCTS.category_id=CATEGORIES.category_id AND
                                                                list_price>=ALL(SELECT P2.list_price FROM PRODUCTS P2);


/* Seleccionar el nombre de productos que no estén en stock (que no exista una fila en la tabla stocks para esos productos) */
SELECT product_name from products WHERE NOT EXISTS(SELECT * FROM stocks WHERE stocks.product_id=products.product_id);


/* Seleccionar productos vendidos a precio diferente del producto */
/* -> Versión procedente del AR */
SELECT product_name FROM products, order_items WHERE order_items.product_id=products.product_id AND order_items.list_price <> products.list_price;
/* -> Versión procedente del CR */
SELECT product_name FROM products WHERE EXISTS(SELECT * FROM order_items WHERE order_items.product_id=products.product_id AND order_items.list_price <> products.list_price);




/**** EJERCICIOS: ****/
/* 11. Seleccionar Descuento mínimo, máximo y promedio que se hace de los items vendidos */
/* 12. Seleccionar Descuento mínimo, máximo y promedio que se hace de los items vendidos a personas de New York */
/* 13. Seleccionar marcas que tengan algún producto que no esté en stock */
/* 14. Seleccionar categorías que no tengan productos que no estén en stock (PISTA: Usar 3 consultas anidadas haciendo uso de NOT EXISTS) */
/* 15. Seleccionar nombres de productos que no hayan sido vendidos */
/* 16. Seleccionar nombre de clientes que hayan comprado la máxima cantidad de algún producto, junto con el nombre del producto */
/* 17. Seleccionar nombre y apellidos de personal que no haya vendido nada en 2016 (es decir, que no haya procesado pedidos en ese año) */
/* 18. Seleccionar nombres de tiendas y clientes que sean de la misma ciudad */
/* 19. Seleccionar nombres de tiendas y clientes que sean de la misma ciudad, y donde los clientes hayan hecho pedidos a otras tiendas que no sean esas */
/* 20. Seleccionar nombres de clientes y su ciudad que hayan comprado los productos más caros. */


/* Nombre e ID de los productos que no hayan sido vendidos, usando operadores conjuntistas */
SELECT product_name, product_id FROM products WHERE products.product_id IN(
    (SELECT p2.product_id FROM products p2)
        MINUS
    (SELECT product_id FROM order_items)
);


/* Selección del nombre y apellidos de clientes que vivan en una ciudad que no tiene tienda, usando operadores conjuntistas */
SELECT first_name, last_name FROM customers WHERE city IN (
    (SELECT city FROM customers)
        MINUS
    (SELECT city FROM stores)
);


/* Selección del nombre y apellidos de clientes que vivan en una ciudad que tiene tienda */
SELECT first_name, last_name FROM customers WHERE city IN (
    SELECT city FROM stores
);


/* Selección del email de las tiendas y de su personal */
(SELECT email FROM stores)
    UNION
(SELECT email from staffs);


/**** EJERCICIOS: HACERLOS HACIENDO USO DE OPERADORES CONJUNTISTAS ****/
/* 21. Seleccionar nombre de tiendas que tengan en stock productos de al menos dos marcas distintas */
/* 22. Seleccionar nombre y teléfono de clientes que sean de New York o de Bronx */
/* 23. Encontrar el producto de precio máximo USANDO OPERADORES CONJUNTISTAS (sin usar operadores adicionales como min,max,all, etc.)  */
/* 24. Encontrar los nombres de productos que no estén en stock USANDO OPERADORES CONJUNTISTAS  */
/* 25. Encontrar los nombres de productos que hayan sido vendidos por al menos dos tiendas distintas */






