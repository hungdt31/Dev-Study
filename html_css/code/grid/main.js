document.addEventListener('DOMContentLoaded', function () {
    // Create main container
    var mainContainer = document.createElement('div');
    mainContainer.className = 'container-fuild';

    // Create container
    var container = document.createElement('div');
    container.className = 'container';
    const imgInf = [
        {
            name: "John Wick",
            sentence: "“Cuộc đời tôi đang ở cái giai đoạn mà tôi sẽ né mọi loại tranh luận cho nhẹ đầu. Kể cả khi bạn bảo 1 + 1 = 5. Bạn nói chuẩn, xuất sắc!”"
        },
        {
            name: "Stephen King",
            sentence: "“Thời điểm đáng sợ nhất luôn luôn là ngay trước khi bạn bắt đầu. Sau đó, mọi thứ nhất định sẽ tốt đẹp hơn.”"
        },
        {
            name: "Conan O’Brien",
            sentence: "“Hãy làm việc chăm chỉ và lạc quan, và bạn sẽ đạt được mọi thứ mà mình muốn.”"
        },
        {
            name: "Mahatma Gandhi",
            sentence: "“Nếu bạn muốn thay đổi thế giới, hãy bắt đầu bằng việc thay đổi chính mình.”"
        },
        {
            name: "Nhà Giả Kim",
            sentence: "“Khi bạn khao khát một điều gì đó, cả vũ trụ sẽ hợp lực giúp bạn đạt được điều đó.”"
        },
        {
            name: "Steve Maraboli",
            sentence: "“Hạnh phúc không phải là điều đã đến mà là điều đang được tạo nên. Nó không phải là một đích mà là một hành trình.”"
        },
    ]
    // Create items
    for (var i = 1; i <= 6; i++) {
        var item = document.createElement('div');
        item.className = 'item';

        var img = document.createElement('img');
        img.src = 'item' + i + '.jpg';
        img.alt = '';

        var content = document.createElement('div');
        content.className = 'content';

        var innerDiv = document.createElement('div');

        var title = document.createElement('h2');
        title.textContent = imgInf[i-1].name;

        var description = document.createElement('div');
        description.className = 'des';
        description.textContent = imgInf[i-1].sentence;
        innerDiv.appendChild(title);
        innerDiv.appendChild(description);

        content.appendChild(innerDiv);

        item.appendChild(img);
        item.appendChild(content);

        container.appendChild(item);
    }

    mainContainer.appendChild(container);

    // Create footer
    var footer = document.createElement('footer');
    var footerTitle = document.createElement('h1');
    footerTitle.textContent = 'Koi Koi';
    footer.appendChild(footerTitle);

    var ul = document.createElement('ul');
    var menuItems = [
        'Facebook: https://www.facebook.com/profile.php?id=100026377400074', 
        'Instagram: https://www.instagram.com/doantri.hung/', 
        'Gmail: koikoidth12@gmail.com'
    ];

    for (var i = 0; i < menuItems.length; i++) {
        var li = document.createElement('li');
        var infoContent = document.createElement('div');
        var linkInfo = document.createElement('a');
        var info = document.createElement('p');
        info.textContent = menuItems[i].split(' ')[0];
        linkInfo.innerHTML = menuItems[i].split(' ')[1];
        linkInfo.href = menuItems[i].split(' ')[1];
        infoContent.appendChild(info);
        infoContent.appendChild(linkInfo);
        li.appendChild(infoContent);
        ul.appendChild(li);
    }
    footer.appendChild(ul);
    mainContainer.appendChild(footer);

    // Append the main container to the body
    document.body.appendChild(mainContainer);
});
