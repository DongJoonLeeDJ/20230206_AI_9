create table mvc_board (
bid int primary key not null auto_increment,
bName varchar(20) default null,
bTitle varchar(100) default null,
bContent varchar(300) default null,
bDate timestamp null default current_timestamp,
bHit int default 0,
bGroup int default null,
bStep int default null,
bIndent int default null
) charset=utf8mb4;