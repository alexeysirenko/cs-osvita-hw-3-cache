FROM debian:latest

RUN apt update && apt install -y \
  build-essential \
  gcc \
  make \
  valgrind \
  python3

WORKDIR /root
