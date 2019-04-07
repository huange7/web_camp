package com.My_login.Dao;

import com.My_login.model.User;

import java.sql.SQLException;
import java.util.List;

public interface BasicOperation {
    public int updateUser(User user) throws Exception;
    public List<User> searchAll(String username) throws Exception;
    public User searchUser(String username) throws Exception;
    public List<User> lookOver(String username) throws Exception;
}
