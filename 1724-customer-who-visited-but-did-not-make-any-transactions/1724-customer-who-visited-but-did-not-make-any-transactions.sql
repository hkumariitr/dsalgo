# Write your MySQL query statement below
select customer_id, Count(customer_id) as count_no_trans
from Visits v
-- Left Join Transactions t on t.visit_id = v.visit_id
where v.visit_id not in (select visit_id from transactions)
group by customer_id;