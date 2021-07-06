package:
	docker build -t monolish-debian-package docker
	docker cp $(shell docker create monolish-debian-package:latest):/monolish/$(shell docker run --rm monolish-debian-package:latest ls | grep ".*\.deb$$") .
