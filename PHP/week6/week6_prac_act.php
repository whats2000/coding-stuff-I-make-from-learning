<?php
    $link = mysqli_connect("localhost", "whats2000_", "123456789", "php_course");

    if (!$link) {
        printf("Could not connect : %s\n", mysqli_connect_error());
        exit("無法訪問");
    }

    $search_value = $_POST['acc'];

    $sql = "SELECT `mid`, `acc`, `pass` FROM `member` where `acc` like '%$search_value%'";

    // 執行 SQL 訪問
    $result = mysqli_query($link, $sql);
    
    // 檢驗回傳數量
    $num = mysqli_num_rows($result);

    if ($num > 0) { ?>
        <!DOCTYPE html>
        <html lang="en">
            <table border="1">
                <tr>
                    <td>編號</td>
                    <td>帳號</td>
                    <td>密碼</td>
                </tr>
                <?php foreach ($result as $key => $value) { ?>
                    <tr>
                        <td><?=$value['mid']?></td>
                        <td><?=$value['acc']?></td>
                        <td><?=$value['pass']?></td>
                    </tr>
                <?php } ?>
            </table>
        </html>
    <?php } else { ?>
        <text style="color: gray;">目前無相關會員資料</text>
    <?php } ?>