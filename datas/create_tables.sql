
DROP TABLE IF NOT EXISTS products;
DROP TABLE IF NOT EXISTS warehouse;
DROP TABLE IF NOT EXISTS productsenroll;

CREATE TABLE products (
    productfeild TEXT NOT NULL,
    Id INTEGER NOT NULL PRIMARY KEY,
    count INTEGER ;

);

CREATE TABLE warehouse{
    Id INTEGER PRIMARY key,
};


CREATE TABLE productsenroll{
    werehous_id INTEGER NOT NULL,
    product_id INTEGER NOT NULL,

    FOREIGN KEY (werehous_id) REFERENCES warehouse(Id),
    FOREIGN KEY (product_id) REFERENCES products(Id),

    UNIQUIE(werehous_id,product_id)
};


/*
smartphones
stock level =%80
product movment based on this month=weaker than last month
alert stage= above %15 no alert
*/