package com.My_login.service.impl;

import com.My_login.Dao.Impl.UserDaoImpl;
import com.My_login.model.User;
import com.My_login.service.LoginService;
import com.My_login.util.MD5Util;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;



/**
 * @author huange7
 */
public class LoginServiceImpl implements LoginService {
    @Override
    public void loginCheck(String username, String password, HttpServletRequest request, HttpServletResponse response) throws Exception {
        UserDaoImpl ud = new UserDaoImpl();
        User user = new User();
        user.setName(username);
        user.setPassword(password);
        user.setStatus(ud.judgeStatus(username));
        if(ud.LoginRight(username,password) == true){
                request.getSession().setAttribute("username",username);
                request.getSession().setAttribute("status", user.getStatus());
                response.sendRedirect("/My_login_war_exploded/User.jsp");
        }else{
                response.sendRedirect("/My_login_war_exploded/LoginFailure.jsp");
        }
    }
}
