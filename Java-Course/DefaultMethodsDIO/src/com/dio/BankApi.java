package com.dio;

import com.dio.entity.Statement;
import com.dio.entity.User;
import com.dio.service.StatementService;
import com.dio.service.StatementServiceImpl;

import java.io.IOException;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.time.LocalDateTime;
import java.util.List;
import java.util.UUID;

public class BankApi {
    public static void main(String[] args) throws IOException, InterruptedException {
        final User userA = new User(UUID.randomUUID(), "UserA");
        final User userB = new User(UUID.randomUUID(), "UserB");
        final StatementService statementService =
                new StatementServiceImpl(userA, userB);

        statementService.findAllByUser(userA).forEach(System.out::println);
        statementService.findAllByUser(userB).forEach(System.out::println);

        List<Statement> statementsUserA = statementService.findAllByUser(userA);
        for (Statement statement : statementsUserA){
            LocalDateTime localDateTime = statement.getCreatedAt();
            System.out.println("Date plus one day: " + localDateTime.plusDays(1));
            System.out.println("Day of year: " + localDateTime.getDayOfYear());
            System.out.println("Day of month: " + localDateTime.getDayOfMonth());
        }

        statementsUserA.forEach(statement -> {
            System.out.println(statement.getUser().toString());
        });

        String test = "    This       is     a    \uD83D\uDE44     test.   \n\r\t   ";
        System.out.println("|"+ test.trim() +"|");

        final HttpClient httpClient = HttpClient.newBuilder()
                .version(HttpClient.Version.HTTP_2).build();
        final HttpRequest httpRequest = HttpRequest.newBuilder()
                .uri(URI.create("https://www.google.com/manifest?pwa=webhp"))
                .GET().version(HttpClient.Version.HTTP_2)
                .build();
        final HttpResponse<String> strHttpResponse = httpClient
                .send(httpRequest, HttpResponse.BodyHandlers.ofString());
        System.out.println(strHttpResponse.statusCode());
        System.out.println(strHttpResponse.body());

    }
}
