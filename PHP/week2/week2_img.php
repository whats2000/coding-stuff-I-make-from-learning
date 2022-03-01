<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>上傳圖片</title>
</head>
<body>
    <form action="week2_img_act.php" method="POST" autocomplete="off"  enctype="multipart/form-data">
        <input type="file" name="file" accept=".jpg, .png">
        <button type="submit">提交</button>
    </form>
</body>
</html>