<%--
  Created by IntelliJ IDEA.
  User: Administrator
  Date: 2019/4/6/006
  Time: 20:17
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title>-ERROR-</title>
    <link rel="stylesheet" type="text/css" href="css/LoginFailure.css" />
    <script type="text/javascript">
        function countDown(secs,surl){
            var jumpTo = document.getElementById('jumpTo');
            jumpTo.innerHTML=secs;
            if(--secs>0){
                setTimeout("countDown("+secs+",'"+surl+"')",1000);
            }
            else{
                location.href=surl;
                -ma
            }
        }
    </script>
</head><br>
<body>
<body style="background:url(image/login.jpg) ;background-size:cover; "></body>
<div id = "div1">
    <h1><br>该用户名已被注册！</h1>
    <a id = "a1" href="/My_login_war_exploded/Register.jsp"><span id="jumpTo">5</span>秒后系统会自动跳转，也可点击本处直接跳</a>
</div>
<script type="text/javascript">
    countDown(5,"/My_login_war_exploded/Register.jsp");
</script>
</body>
</html>