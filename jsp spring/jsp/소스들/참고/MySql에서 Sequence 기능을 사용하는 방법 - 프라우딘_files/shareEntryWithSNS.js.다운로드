var ShareEntryWithSNS = {
	services : [ 'twitter', 'facebook', 'kakaostory' ],
	actionUrl : '/plugin/sendSNS_Message',
	popupSize : {
		normal : {
			w : 800,
			h : 500
		},
		small : {
			w : 472,
			h : 340
		}
	},
	share : function(service, entryId, entryTitle) {
		if (service && entryId && entryTitle) {
			for ( var i = 0, s; s = this.services[i]; i++) {
				if (service == s) {
					this.post(service, entryId, entryTitle);
					break;
				}
			}
		}
	},
	post : function(service, entryId, entryTitle) {
		var popupSize = this.popupSize;
		var popupWidth = popupSize.normal.w;
		var popupHeight = popupSize.normal.h;
		var url = this.actionUrl + '?service=' + service + '&entryId=' + entryId + '&title=' + encodeURIComponent(entryTitle);
		window.open(url, service, 'width=' + popupWidth + ', height=' + popupHeight + ',resizable=yes,scrollbars=yes');
	}
};