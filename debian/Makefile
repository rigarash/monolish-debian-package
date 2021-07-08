package:
	docker build -t monolish-debian-package docker
	sleep 2
	docker cp $(shell docker create monolish-debian-package:latest):/monolish/$(shell docker run --rm monolish-debian-package:latest ls | grep ".*\.deb$$") .
