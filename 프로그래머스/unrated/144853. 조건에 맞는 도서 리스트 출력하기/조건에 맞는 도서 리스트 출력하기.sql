select BOOK_ID, date_format(PUBLISHED_DATE, '%Y-%m-%d') as PUBLISHED_DATE  from BOOK 
where CATEGORY = '인문' and PUBLISHED_DATE >= '2021-01-01' and PUBLISHED_DATE < '2022-01-01'
order by PUBLISHED_DATE