SELECT board.TITLE, board.BOARD_ID, reply.REPLY_ID, reply.WRITER_ID, reply.CONTENTS, date_format(reply.CREATED_DATE, '%Y-%m-%d') AS CREATED_DATE
FROM USED_GOODS_BOARD board
JOIN USED_GOODS_REPLY reply ON board.BOARD_ID = reply.BOARD_ID
WHERE board.CREATED_DATE >= '2022-10-01' AND board.CREATED_DATE < '2022-11-01'  
ORDER BY reply.CREATED_DATE ASC, board.TITLE ASC;