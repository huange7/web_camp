package com.My_login.service.impl;

import com.My_login.Dao.Impl.UserDaoImpl;
import com.My_login.model.User;
import com.My_login.service.RegisterService;
import com.My_login.util.MD5Util;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class RegisterServiceImpl implements RegisterService {
    @Override
    public void RegisterCheck(String username, String password, HttpServletRequest request, HttpServletResponse response) throws Exception {
        UserDaoImpl ud = new UserDaoImpl();
        User user = new User();
        user.setName(username);
        user.setPassword(password);
        if(ud.usernameIsExist(username) == true){
            response.sendRedirect("/My_login_war_exploded/RegisterFailure.jsp");
        }else{
            UserDaoImpl ud2 = new UserDaoImpl();
            ud2.addUser(user);
            response.sendRedirect("/My_login_war_exploded/RegisterSuccess.jsp");
        }

    }
}
