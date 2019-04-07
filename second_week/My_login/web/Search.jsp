<%@page import="com.My_login.Dao.Impl.BasicOperationImpl"%>
<%@page import="com.My_login.model.User" %>
<%@ page import="java.util.List" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<html>
<head>
    <title>查询结果</title>
    <link rel="stylesheet" type="text/css" href="css/Search.css" />
</head>
<body>
    <body style="background:url(image/User.jpg) ;background-size:cover; "></body>
    <%
        String username = (String) request.getSession().getAttribute("username");
        BasicOperationImpl basicOperation = new BasicOperationImpl();
        List<User> list = basicOperation.searchAll(username);
        int i = 1;
        String  status ;
    %>
        <table width="537" height="90" border="1" class = "table1">
            <caption class = "cap1">用户管理</caption>
            <br>
            <tr>
                <th width="56" class = "th">记录
                <th width="92" class = "th">用户名</th>
                <th width="56" class = "th">身份</th>
                <th width="56" class = "th">操作</th>
            </tr>
            <% for(User user1:list){  %>
            <tr>
                <%
                    if(user1.getStatus() == 1){
                        status = "普通用户";
                    }else if(user1.getStatus() == 2){
                        status = "管理员";
                    }else{
                        status = "超级管理员";
                    }
                %>
                <td align="center" class = "td"><%=i++ %> </td>
                <td align="center" class = "td"><%=user1.getName() %> </td>
                <td align="center" class = "td"><%=status%></td>
                <td align="center" class = "td"><a href="doUpData.jsp?username=<%=user1.getName()%>" class="a">修改</a></td>
            </tr>
            <% }%>

        </table>
</body>
</html>
