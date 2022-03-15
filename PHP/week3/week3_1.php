<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>第3周練習1</title>
</head>
<body>
    <form action="week3_1_act.php" method="post">
        <label for="stu_id">學號 : </label>
        <input type="text" name="stu_id" id="stu_id">

        <br>

        <label for="stu_name">姓名 : </label>
        <input type="text" name="stu_name" id="stu_name">
        
        <br>

        <label for="stu_birth">生日 : </label>
        <input type="date" name="stu_birth" id="stu_birth">

        <br>

        <button type="submit">提交</button>
    </form>
</body>
</html>