package com.My_login.service.impl;

import com.My_login.Dao.Impl.UserDaoImpl;
import com.My_login.service.UserService;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * @author huange7
 */
public class UserServiceImpl implements UserService {
    @Override
    public void userService(String username,HttpServletRequest request, HttpServletResponse response) throws Exception {
        UserDaoImpl userDaoImpl = new UserDaoImpl();
        int status = userDaoImpl.judgeStatus(username);
        if(status > 1)
        {
            response.sendRedirect("/My_login_war_exploded/Search.jsp");
        }else{
            response.sendRedirect("/My_login_war_exploded/PowerLessly.jsp");
        }
    }
}
