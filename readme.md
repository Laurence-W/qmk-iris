QMK MSYS:
qmk config user.keymap=laurence
qmk config user.keyboard=keebio/iris/rev7
qmk compile
(flash with qmk toolbox) or,
qmk flash -kb keebio/iris/rev7 -km laurence
