FROM ubuntu:latest

RUN useradd -ms /bin/sh chall

COPY ./entrypoint.sh /entrypoint.sh
COPY ./chall /home/chall

RUN chown -R root:root /home/chall
RUN chmod +x /entrypoint.sh

RUN chown -R chall:chall /home/chall
RUN chmod +x /home/chall/server

EXPOSE 2025

CMD ["/entrypoint.sh"]
