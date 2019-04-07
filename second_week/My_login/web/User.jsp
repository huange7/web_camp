
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <link rel="stylesheet" type="text/css" href="css/User.css" />
    <title>-酒店管理界面-</title>
    <meta http-equiv="Content-Type" content="text/html;charset=UTF-8">
</head>
    <body>
        <body style="background:url(image/User.jpg) ;background-size:cover; "></body>
            <div id = "div1">
                <h1>-酒店管理界面-</h1>
            </div>
            <div id ="main">
                <form   name="form3" action="servlet/UserServlet" method="post">
                    <p>
                        <button class="button2" type="submit">更新权限</button>
                    </p>
                </form>
                <form action="Search1.jsp" method="post">
                    <p>
                        <button class="button1" type="submit">查看用户</button>
                    </p>
                </form>
                <form action="MyService.jsp" method="post">
                    <p>
                        <button class="button3" type="submit">我的服务</button>
                    </p>
                </form>
            </div>
    </body>
</html>
