package com.My_login.Dao;

import com.My_login.model.User;

public interface UserDao {

    /**
     * 更新用户信息
     * @param user
     * @param newPassword
     * @return
     * @throws Exception
     */
    public boolean update(User user, String newPassword) throws Exception;

    /**
     * 添加新用户（注册）
     * @param user
     * @return
     * @throws Exception
     */
    public boolean addUser(User user) throws Exception;

    /**
     * 检测用户是否存在
     * @param username
     * @return
     * @throws Exception
     */
    public boolean usernameIsExist(String username) throws Exception;


    /**
     * 检查登录信息是否正确
     * @param username
     * @param password
     * @return
     * @throws Exception
     */
    public boolean LoginRight(String username, String password) throws Exception;
    public int judgeStatus(String username)throws Exception;
}
