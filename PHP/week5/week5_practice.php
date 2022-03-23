<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>week5練習</title>
</head>
<body>
    <label for="acc">帳號</label>
    <input type="text" name="acc" id="acc"/>

    <br>

    <label for="pass">密碼</label>
    <input type="password" name="pass" id="pass"/>

    <br>

    <button type="submit" id="login">登錄</button>

    <br>

    <img src="./like.png" alt="" id="like">

    <script src="https://code.jquery.com/jquery-3.5.0.min.js"></script>
    <script>
        // 點擊觸發事件
        $("#like").on("click", function(){
            // 取得id=like的圖片的路徑
            var like = $("#like").attr("src")

            // 假如未按讚，則換成已按讚的圖片
            if(like == "./like.png"){
                $("#like").attr("src", "./like_black.png")
            }else{// 假如已按讚，則換成未按讚的圖片
                $("#like").attr("src", "./like.png")
            }
            
        })

        $("#login").on("click", function(){
            var acc = $("#acc").val();
            var pass = $("#pass").val();

            $.ajax({
                url : "week5_ajax.php",
                data : "&pass=" + pass + "&acc=" + acc,
                type : "POST",
                dataType :'json'
            }).done(function(data){
                if(data['status'] == "ok"){
                    alert("註冊成功");
                    $("#like").attr("src", "./like.png")
                }else if (data['status'] == "no"){
                    alert("註冊失敗");
                    $("#like").attr("src", "./like_black.png")
                }
            });
        })
    </script>
</body>
</html>