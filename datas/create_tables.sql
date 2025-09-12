
DROP TABLE IF NOT EXISTS products;
DROP TABLE IF NOT EXISTS warehouse;
DROP TABLE IF NOT EXISTS productsenroll;

CREATE TABLE products (
    field TEXT NOT NULL,
    Id INTEGER NOT NULL PRIMARY KEY,
    count INTEGER,
    sellmotion TEXT NOT NULL,
    alert TEXT 

);

CREATE TABLE requests(
    requestfield TEXT NOT NULL,
    requestscontent TEXT 
);

CREATE TABLE warehouse{
    Id INTEGER PRIMARY key,
    warehousetype TEXT NOT NULL,
    filledspace INTEGER,
    warhouseinforms TEXT,
    branch INT NOT NULL
};

CREATE TABLE branch{
    branchnum int NOT NULL,
    storingwarehousetypes TEXT
}

CREATE TABLE vendcare
{
    vendorid TEXT NOT NULL,
    vendorstatement TEXT,
    vendorsinforms TEXT,
    sellmotion TEXT

};  
    
   /*
    productsstatements TEXT ,
    category TEXT NOT NULL,
    branchreport TEXT*/


CREATE TABLE productsenroll{
    werehous_id INTEGER NOT NULL,
    product_id INTEGER NOT NULL,

    FOREIGN KEY (werehous_id) REFERENCES warehouse(Id),
    FOREIGN KEY (product_id) REFERENCES products(Id),

  
    UNIQUE(werehous_id,product_id)
};


/*
smartphones
stock level =%80
product movment based on this month=weaker than last month
alert stage= above %15 no alert
*/