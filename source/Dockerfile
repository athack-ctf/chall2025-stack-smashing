FROM ubuntu:latest

RUN useradd -ms /bin/sh chall

WORKDIR /home/chall

COPY ./chall /home/chall

RUN chown -R chall:chall /home/chall

USER chall

RUN chmod +x /home/chall/run.sh

EXPOSE 2025

CMD ["./run.sh"]
