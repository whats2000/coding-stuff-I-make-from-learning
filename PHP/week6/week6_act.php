<?php

// 使用success的方法
// echo "表單已提交<br>";
// print_r($_POST);


// 使用done的方法
exit(json_encode($_POST));

// 想試試看錯誤會印出什麼的話，可以把這行下面的註解刪掉，上面兩行註解
// $link = mysqli_connect("localhost", "", "P4EWfX5EAwg3rPI5", "php_course");
