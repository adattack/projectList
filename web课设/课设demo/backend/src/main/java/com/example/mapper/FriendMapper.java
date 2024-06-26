package com.example.mapper;

import com.example.entity.User;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;


@Mapper
public interface FriendMapper {

    public List<User> getFriends(Integer userId);

}
