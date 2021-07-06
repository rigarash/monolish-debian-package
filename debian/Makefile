package:
	docker build -t monolish-debian-package docker
	docker run --rm --entrypoint cat monolish-debian-package $(shell docker run --rm monolish-debian-package ls | grep ".*\.deb$$") > $(shell docker run monolish-debian-package ls | grep ".*\.deb$$")
