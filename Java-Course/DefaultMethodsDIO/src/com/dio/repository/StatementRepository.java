package com.dio.repository;

import com.dio.entity.Statement;
import com.dio.entity.User;

import java.math.BigDecimal;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.List;
import java.util.stream.Collectors;

public class StatementRepository {
    private final List<Statement> statements;

    public StatementRepository(User userA, User userB) {
        final DateTimeFormatter dateTimeFormatter = DateTimeFormatter.ISO_OFFSET_DATE_TIME;
        statements = List.of(
                new Statement(new BigDecimal("10.00"), LocalDateTime.parse("2021-11-15T00:00:00-03:00",dateTimeFormatter), userA),
                new Statement(new BigDecimal("20.00"), LocalDateTime.parse("2021-11-15T00:00:00-03:00",dateTimeFormatter), userA),
                new Statement(new BigDecimal("9.90"), LocalDateTime.parse("2021-11-15T00:00:00-03:00",dateTimeFormatter), userA),
                new Statement(new BigDecimal("1.00"), LocalDateTime.parse("2021-11-15T00:00:00-03:00",dateTimeFormatter), userA),
                new Statement(new BigDecimal("500.73"), LocalDateTime.parse("2021-11-15T00:00:00-03:00",dateTimeFormatter), userA),
                new Statement(new BigDecimal("100.00"), LocalDateTime.parse("2021-11-15T00:00:00-03:00",dateTimeFormatter), userB),
                new Statement(new BigDecimal("150.14"), LocalDateTime.parse("2021-11-15T00:00:00-03:00",dateTimeFormatter), userB),
                new Statement(new BigDecimal("2.99"), LocalDateTime.parse("2021-11-15T00:00:00-03:00",dateTimeFormatter), userB),
                new Statement(new BigDecimal("3.00"), LocalDateTime.parse("2021-11-15T00:00:00-03:00",dateTimeFormatter), userB)
        );
    }

    public List<Statement> findAllByUser(User user) {
        return this.statements.stream().filter(
                stat -> stat.getUser().equals(user)
        ).collect(Collectors.toList());
    }
}
