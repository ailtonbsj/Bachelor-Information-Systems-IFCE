package com.dio.entity;

import java.util.UUID;

public class User {
    UUID cod;
    String name;

    public User(UUID cod, String name) {
        this.cod = cod;
        this.name = name;
    }

    public UUID getCod() {
        return cod;
    }

    public void setCod(UUID cod) {
        this.cod = cod;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "User{" +
                "cod=" + cod +
                ", name='" + name + '\'' +
                '}';
    }
}
