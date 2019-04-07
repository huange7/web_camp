package com.My_login.Dao.Impl;

import com.My_login.Dao.BasicOperation;
import com.My_login.model.User;
import com.My_login.util.DbUtil;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

/**
 * @author huange7
 */
public class BasicOperationImpl implements BasicOperation {
    private static DbUtil dbUtil = new DbUtil();
    @Override
    public int updateUser(User user) throws Exception{
        Connection con = dbUtil.getCon();
        PreparedStatement pstmt = null;
        int result = 0;
        try {
            String sql = "update db_user set status=? where username=?";
            pstmt = con.prepareStatement(sql);
            pstmt.setInt(1, user.getStatus());
            pstmt.setString(2, user.getName());
            result = pstmt.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            dbUtil.close(pstmt, con);
        }
        return result;
    }

    @Override
    public List<User> searchAll(String username) throws Exception {
        List<User> userList = new ArrayList<>();
        UserDaoImpl userDao = new UserDaoImpl();
        Connection conn = dbUtil.getCon();
        int temp = userDao.judgeStatus(username);
        PreparedStatement pstmt = null;
        try {
            String sql = "select *from db_user where status < ?";
            pstmt = conn.prepareStatement(sql);
            pstmt.setInt(1, temp);
            ResultSet rs = pstmt.executeQuery();
            while(rs.next()){
                User user1 = new User();
                user1.setName(rs.getString("username"));
                user1.setStatus(rs.getInt("status"));
                userList.add(user1);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            dbUtil.close(pstmt, conn);
        }
        return userList;
    }



    @Override
    public User searchUser(String username) throws Exception {
        User user = new User();
        Connection conn = dbUtil.getCon();
        PreparedStatement pstmt = null;
        String sql = "select *from db_user where username = ?";
        try {
;           pstmt = conn.prepareStatement(sql);
            pstmt.setString(1,username);
            ResultSet rs = pstmt.executeQuery();
            if(rs.next()){
                user.setName(username);
                user.setPassword(rs.getString("password"));
                user.setStatus(rs.getInt("status"));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            dbUtil.close(pstmt, conn);
        }
        return user;
    }

    @Override
    public List<User> lookOver(String username) throws Exception {

        List<User> userList = new ArrayList<>();
        UserDaoImpl userDao = new UserDaoImpl();
        Connection conn = dbUtil.getCon();
        PreparedStatement pstmt = null;
        try {
            String sql = "select *from db_user ";
            pstmt = conn.prepareStatement(sql);
            ResultSet rs = pstmt.executeQuery();
            while(rs.next()){
                User user1 = new User();
                user1.setName(rs.getString("username"));
                user1.setStatus(rs.getInt("status"));
                userList.add(user1);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            dbUtil.close(pstmt, conn);
        }
        return userList;
    }
}
