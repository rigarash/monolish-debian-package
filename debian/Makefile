package:
	docker build -t monolish-debian-package docker
	docker run --rm --volume=$(abspath ..):/monolish/monolish-debian-package --gpus all --cap-add SYS_ADMIN monolish-debian-package
