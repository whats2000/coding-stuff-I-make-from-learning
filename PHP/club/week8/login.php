<?php
session_start();

if (isset($_SESSION["name"])) { ?>

<script>
alert('您已登錄')
window.location.href = './index.php'
</script>

<?php
} ?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>相片資料庫 - 登入</title>

    <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.10.2/dist/umd/popper.min.js"
        integrity="sha384-7+zCNj/IqJ95wo16oMtfsKbZ9ccEh31eOz1HGyDuCQ6wgnyJNSYdrPa03rtR1zdB" crossorigin="anonymous">
    </script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.min.js"
        integrity="sha384-QJHtvGhmr9XOIpI6YVutG+2QOK9T+ZnN4kzFN1RtK3zEFEIsxhlmWl5/YESvpZ13" crossorigin="anonymous">
    </script>

    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet"
        integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
</head>

<body>
    <div class="container">
        <div class="row justify-content-center">
            <div class="col-sm-5">
                <form action="member.php" method="post">
                    <input type="hidden" id="method" name="method" value="login">

                    <div class="mb-3">
                        <label for="acc" class="format-label">帳號</label>
                        <input type="text" class="form-control" id="acc" name="acc" />
                    </div>
                    <div class="mb-3">
                        <label for="pass" class="format-label">密碼</label>
                        <input type="text" class="form-control" id="pass" name="pass" />
                    </div>
                    <div class="mb-2 d-grid mx-auto">
                        <button type="submit" class="btn btn-dark" id="login">登入</button>
                    </div>
                </form>

                <div class="d-grid mx-auto">
                    <button type="submit" class="btn btn-dark" id="register" data-bs-toggle="modal"
                        data-bs-target="#registerModal">註冊</button>
                </div>
            </div>

        </div>
    </div>
</body>

<!-- registerModal -->
<div class="modal fade" id="registerModal" tabindex="-1" aria-labelledby="registerModalLabel" aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <h5 class="modal-title" id="registerModalLabel">註冊帳號</h5>
                <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
            </div>
            <form action="member.php" method="post">
                <input type="hidden" id="method" name="method" value="register">

                <div class="modal-body">
                    <div class="mb-3">
                        <label for="acc" class="format-label">帳號</label>
                        <input type="text" class="form-control" id="acc" name="acc" required />
                    </div>
                    <div class="mb-3">
                        <label for="pass" class="format-label">密碼</label>
                        <input type="text" class="form-control" id="pass" name="pass" required />
                    </div>
                </div>
                <div class="modal-footer">
                    <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">關閉</button>
                    <button type="submit" class="btn btn-dark">註冊</button>
                </div>
            </form>

        </div>
    </div>
</div>

</html>