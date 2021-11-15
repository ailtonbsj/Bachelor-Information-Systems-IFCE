package com.dio.entity;

import java.math.BigDecimal;
import java.time.LocalDateTime;

public class Statement {
    private BigDecimal value;
    private LocalDateTime createdAt;
    private User user;

    public Statement(BigDecimal value, LocalDateTime createdAt, User user) {
        this.value = value;
        this.createdAt = createdAt;
        this.user = user;
    }

    public User getUser() {
        return user;
    }

    public void setUser(User user) {
        this.user = user;
    }

    public BigDecimal getValue() {
        return value;
    }

    public void setValue(BigDecimal value) {
        this.value = value;
    }

    public LocalDateTime getCreatedAt() {
        return createdAt;
    }

    public void setCreatedAt(LocalDateTime createdAt) {
        this.createdAt = createdAt;
    }

    @Override
    public String toString() {
        return "Statement{" +
                "value=" + value +
                ", createdAt=" + createdAt +
                ", user=" + user +
                '}';
    }
}
