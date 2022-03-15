<?php
    $link = mysqli_connect("localhost", "whats2000_", "123456789", "php_couse");
    
    if (!$link) {
        printf("Could not connect : %s\n", mysqli_connect_error());
        exit();
    }
    