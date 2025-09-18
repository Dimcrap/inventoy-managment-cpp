INSERT INTO branch(branchnum,storingwarehousestype,branchinform)
VALUES
(1,'collabrativestorage','branch shipping level is high demands performs with delay'),
(2,'vendorstorage','this branch must send more vending status'),
(3,'vendorstorage','NULL');


INSERT INTO warehouse(Id,warehousetype,filledspace,warhouseinforms,branch)
VALUES 
(1123,'collabrativestorage',40,'warehouse will send recharge request soon',1),
(2123,'collabrativestorage',60,'warehouse demands is still high as last month',1),
(3123,'vendorstorage',60,'NULL',2),
(4123,'vendorstorage',70,'vending there will be more storing slot in futur',3);

/*smartphones,tablets,smartwatchs,accessories*/

INSERT INTO products(field,Id,count,sellmotion,alert,warehousID)
VALUES
	('accessorie',0001,420,'+%30','NULL',1123),
	('smartwatchs',0002,427,'-%5','NULL',2123),
	('tablets',0003,570,'-%30','NULL',3123),
	('tablets',0005,0,'%0','NULL',3123),
	('smartphones',0004,150,'+%73','low storage detected!',4123);

INSERT INTO requests(requestfield,requestscontent)
	VALUES
	('smartphones','200 count of product for 3123'),
	('accessories','150 count of product for 1123');


INSERT INTO vendcare(vendorid,vendorstatement,vendorsinforms,sellmotion)
VALUES
('A234','products quality can be more suitable','NULL','+%12'),
('S234','there will be various requestfield in future',
'smarphones getting discount this month','+%42'),
('D234','NULL','demand for more coopereate with survey protocol for efficient process','+%20');
