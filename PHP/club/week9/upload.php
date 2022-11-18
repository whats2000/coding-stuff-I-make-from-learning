<?php

include("./config.php");
session_start();
?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.rtl.min.css" integrity="sha384-+qdLaIRZfNu4cVPK/PxJJEy0B0f3Ugv8i482AKY7gwXwhaCroABd086ybrVKTa0q" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>
    <title>上傳相片</title>
</head>
<body>
    <div class="container">
        <div class="row justify-content-center">
            <div class="col-sm-6">
            <form action="photo_process.php" method="post" enctype="multipart/form-data">
                <input type="hidden" name="method" value="upload" >
                <div class="mb-3">
                    <div class="form-floating">
                    <textarea class="form-control" placeholder="請新增相片描述" id="description" name="description" style="height: 100px" required>
                    </textarea>
                    <label for="description">相片描述</label>
                    </div>
                </div>
                <div class="mb-3">
                    <label for="myfile" class="form-label">上傳相片</label>
                    <input name="myfile" class="form-control" type="file" id="myfile" accept=".jpg, .png" required>
                </div>

                <button type="submit" class="btn btn-primary">提交</button>
            </form>
            </div>
        </div>
    </div>
    
</body>
</html>