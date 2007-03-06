# Copyright 1999-2007 Gentoo Foundation
# Distributed under the terms of the GNU General Public License v2
# $Header: /home/cltm/important_backups/router_settings/keenetic_lite_krasovskiy/openwrt/cvs-fast-export/crepo/ITVal-proxy/module/itval-1.0.ebuild,v 1.1 2007/02/12 18:07:20 atomopawn Exp $

inherit eutils flag-o-matic

DESCRIPTION="Iptables policy testing and validation tool"
HOMEPAGE="http://itval.sourceforge.net"
SRC_URI="mirror://sourceforge.net/${PN}/ITVal-${PV}.tar.bz2"

LICENSE="GPL-2"
SLOT="0"
KEYWORDS="~amd64 ~x86"
IUSE=""

DEPEND="sys-devel/bison
	sys-devel/flex"

S="${WORKDIR}/ITVal-${PV}"

src_install(){
	make DESTDIR="${D}" install || die "make install failed"
	doman itval.n
	dodoc README ChangeLog RELEASE AUTHORS
}