SELECT MAX(num) as num FROM  
(SELECT num FROM MyNumbers
group by num
HAVING count(num)=1) as new_table
