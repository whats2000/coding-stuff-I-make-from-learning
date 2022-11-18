<?php
session_start();

if(isset($_SESSION["name"])){
    echo "<script>";
    echo "window.location.href = './index.php';";
    echo "</script>";
    exit();
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.10.2/dist/umd/popper.min.js" integrity="sha384-7+zCNj/IqJ95wo16oMtfsKbZ9ccEh31eOz1HGyDuCQ6wgnyJNSYdrPa03rtR1zdB" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.min.js" integrity="sha384-QJHtvGhmr9XOIpI6YVutG+2QOK9T+ZnN4kzFN1RtK3zEFEIsxhlmWl5/YESvpZ13" crossorigin="anonymous"></script>
    <title>login</title>
</head>
<body>
    <div class="row justify-content-center">
        <div class="col-sm-5">
            <form action="member.php" method="POST"> 
                <input type="hidden" name="method" value="login">
                <div class="mb-3">
                    <label for="account" class="form-label">Account</label>
                    <input type="text" class="form-control" id="account" name="acc">
                </div>
                <div class="mb-3">
                    <label for="password" class="form-label">Password</label>
                    <input type="password" class="form-control" id="password" name="pass">
                </div>
                <button type="submit" class="btn btn-primary">登入</button>
            </form>

            <!-- Button trigger modal -->
            <br>
            <button type="button" class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#register">
            我要註冊！
            </button>
        </div>
    </div>

    

    <div class="modal" tabindex="-1" id="register">
        <div class="modal-dialog">
            <div class="modal-content">
            <div class="modal-header">
                <h5 class="modal-title">註冊</h5>
                <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
            </div>
            <form action="member.php" method="POST"> 
                <div class="modal-body">
                        <input type="hidden" name="method" value="register">
                        <div class="mb-3">
                            <label for="account" class="form-label">Account</label>
                            <input type="text" class="form-control" id="account" name="acc">
                        </div>
                        <div class="mb-3">
                            <label for="password" class="form-label">Password</label>
                            <input type="password" class="form-control" id="password" name="pass">
                        </div>
                </div>
                <div class="modal-footer">
                    <button type="submit" class="btn btn-primary">註冊</button>
                    <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Close</button>
                </div>
                </div>
            </form> 
        </div>
    </div>
    
</body>
</html>