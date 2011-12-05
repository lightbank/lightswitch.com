$(document).ready(function(){
	$("header nav a,h2 a, .btn-02").bind("click",function(e){
		var id = $(this).attr("href");
		$("html,body").animate({
			scrollTop : $(id).offset().top - 35
		},1000);
		e.preventDefault();
	});
	$(".videomenu a").bind("click",function(e){
		var url = $(this).attr("href");
		var regExp = /http:\/\/(www\.)?vimeo.com\/(\d+)($|\/)/;
		var match = url.match(regExp);
		var vimeourl = "http://player.vimeo.com/video/"+match[2]+"?title=0&amp;byline=0&amp;portrait=0";
		$(".videomenu a").removeClass("current");
		$(this).addClass("current");
		$("#videoframe").attr("src",vimeourl);
		e.preventDefault();
	});
	$("#form").validate({
		errorPlacement: function(error,element)
		{
			return true;
		}
	});
});