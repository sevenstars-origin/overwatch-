create table heroes(
                       id serial primary key ,
                       name text not null,
                       role text,
                       win_rate real
);
insert into heroes (name, role, win_rate)
values
    ('源氏', '输出', 0.52),
    ('莱因哈特', '坦克', 0.49),
    ('天使', '支援', 0.51);
select * from heroes;
select name from heroes;
select * from heroes where win_rate>50;
select *from heroes order by win_rate asc
limit 1;