FROM gcc:latest

WORKDIR /app

COPY main.cpp /app

RUN g++ -o gen-ldif main.cpp

ENTRYPOINT ["./gen-ldif"]
