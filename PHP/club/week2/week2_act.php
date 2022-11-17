<?php
    if (!empty($_POST)) {
        print_r($_POST);
    }
    if (!empty($_GET)) {
        print_r($_GET);
    }
    if (!empty($_FILES)) {
        print_r($_FILES);

        if ($_FILES["file"]["error"] != 0) {
            echo "出錯".$_FILES["file"]["error"];
        } else {
            $filename = $_FILES["file"]["name"];
            $dest = "./".$filename;

            if (file_exists("./".$filename)) {
                echo "目前已有檔案存在<br>";
            } else {
                if (move_uploaded_file($_FILES["file"]["tmp_name"], $dest)) {
                    echo "檔案上傳成功";
                    echo "<img src='$dest'>";
                } else {
                    echo "檔案上傳失敗";
                }
            }
        }
    }
