
CREATE TABLE `orderlog` (
  `orderNum` int NOT NULL AUTO_INCREMENT,
  `orderid` int,
  `custid` varchar(40) DEFAULT NULL,
  `bookid` varchar(50) DEFAULT NULL,
  `saleprice` varchar(20) default null,
  `orderLogTime` datetime DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`orderNum`)
);