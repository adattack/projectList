package com.example.mapper;

import com.example.entity.Record;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface RecordMapper {
    public List<Record> getRecord(Integer userId, Integer chatUserId);

    public int addRecord(Record record);

}
