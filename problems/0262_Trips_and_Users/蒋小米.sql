/* Write your PL/SQL query statement below */
   select request_at "Day",
                 round(count(if(t1.status != 'completed', t1.status, null)) /
                       count(t1.status),
                       2) "Cancellation Rate"
            from trips t1
            left join (select users_id
                         from Users
                        where role = 'driver'
                          and banned = 'No') t2
              on t1.driver_id = t2.users_id
            left join (select users_id
                         from Users
                        where role = 'client'
                          and banned = 'No') t3
              on t1.client_id = t3.users_id
           where t2.users_id is not null
             and t3.users_id is not null
             and to_date(t1.request_at, 'yyyy-MM-dd') between
                 to_date('2013-10-01', 'yyyy-MM-dd') and
                 to_date('2013-10-03', 'yyyy-MM-dd')
           group by request_at